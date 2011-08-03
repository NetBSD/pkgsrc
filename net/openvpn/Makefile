# $NetBSD: Makefile,v 1.43 2011/08/03 08:33:32 cheusov Exp $

DISTNAME=	openvpn-2.2.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://swupdate.openvpn.net/community/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openvpn.net/
COMMENT=	Easy-to-use SSL VPN daemon
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		grep:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--enable-password-save
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

USE_OLD_DES_API=	yes
TEST_TARGET=		check

PKG_SYSCONFSUBDIR=	openvpn
DATADIR=		${PREFIX}/share/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EASYRSADIR=		${DATADIR}/easy-rsa
RCD_SCRIPTS=		openvpn

INSTALLATION_DIRS=	${DATADIR}/easy-rsa
INSTALLATION_DIRS+=	${EGDIR}/config
INSTALLATION_DIRS+=	${EGDIR}/keys
INSTALLATION_DIRS+=	${EGDIR}/scripts

REPLACE_SH=		easy-rsa/2.0/*
SUBST_CLASSES+=		pkitool
SUBST_STAGE.pkitool=	post-build
SUBST_MESSAGE.pkitool=	Fixing up default paths to grep & openssl in pkitool.
SUBST_FILES.pkitool=	easy-rsa/2.0/pkitool
SUBST_SED.pkitool=	-e "s|\\(GREP\\)=.*|\\1=\""${GREP:Q}"\"|"
SUBST_SED.pkitool+=	-e "s|\\(OPENSSL\\)=.*|\\1=\""${SSLBASE:Q}/bin/openssl"\"|"

.include "../../mk/bsd.prefs.mk"

OPENVPN_USER?=		openvpn
OPENVPN_GROUP?=		openvpn
PKG_GROUPS=		${OPENVPN_GROUP}
PKG_USERS=		${OPENVPN_USER}:${OPENVPN_GROUP}
PKG_GECOS.${OPENVPN_USER}=	OpenVPN\ server\ user

post-install: post-install-pam
	set -e; cd ${WRKSRC}/easy-rsa/2.0; for file in [a-zR]*; do	\
		case $$file in						\
		*.orig|tmp) ;;						\
		[A-Z]*|*.cnf|vars)					\
			${INSTALL_DATA} $$file ${DESTDIR}${EASYRSADIR} ;; \
		*)	${INSTALL_SCRIPT} $$file ${DESTDIR}${EASYRSADIR} ;; \
		esac;							\
	done
	set -e; cd ${WRKSRC}/sample-config-files; for file in *; do	\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/config;	\
	done
	set -e; cd ${WRKSRC}/sample-scripts; for file in *; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/scripts;	\
	done
	set -e; cd ${WRKSRC}/sample-keys; for file in *; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/keys;		\
	done

.include "options.mk"

# OpenVPN 2.x has a shared module "plugin" architecture that allows
# inserting callbacks into the server for various tasks.
DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif
.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
