# $NetBSD: Makefile,v 1.25 2008/02/20 04:24:17 jlam Exp $
#

DISTNAME=	openvpn-2.1_rc7
PKGNAME=	openvpn-2.1rc7
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://openvpn.net/release/ \
		http://openvpn.net/release/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openvpn.net/
COMMENT=	Easy-to-use SSL VPN daemon
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		grep:run
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes
TEST_TARGET=		check

PKG_SYSCONFSUBDIR=	openvpn
DATADIR=		${PREFIX}/share/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EASYRSADIR=		${DATADIR}/easy-rsa
RCD_SCRIPTS=		openvpn

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-password-save
CONFIGURE_ARGS+=	--disable-dependency-tracking

# Pthread support is still considered very experimental, so don't enable
# it for the default (production) build.
#
#CONFIGURE_ARGS+=	--enable-pthread

INSTALLATION_DIRS=	${DATADIR}/easy-rsa	${EGDIR}/config		\
			${DOCDIR}		${EGDIR}/keys		\
						${EGDIR}/scripts

.include "../../mk/bsd.prefs.mk"

# OpenVPN 2.x has a shared module "plugin" architecture that allows
# inserting callbacks into the server for various tasks.
#
DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif

REPLACE_SH=		easy-rsa/2.0/*
SUBST_CLASSES+=		pkitool
SUBST_STAGE.pkitool=	post-build
SUBST_MESSAGE.pkitool=	Fixing up default paths to grep & openssl in pkitool.
SUBST_FILES.pkitool=	easy-rsa/2.0/pkitool
SUBST_SED.pkitool=	\
	-e "s|\\(GREP\\)=.*|\\1=\""${GREP:Q}"\"|"			\
	-e "s|\\(OPENSSL\\)=.*|\\1=\""${SSLBASE:Q}/bin/openssl"\"|"

post-install:
	cd ${WRKSRC:Q}/easy-rsa/2.0; for file in [a-zR]*; do		\
		case $$file in						\
		*.orig)	;;						\
		[A-Z]*|*.cnf|vars)					\
			${INSTALL_DATA} $$file ${DESTDIR}${EASYRSADIR:Q} ;;	\
		*)	${INSTALL_SCRIPT} $$file ${DESTDIR}${EASYRSADIR:Q} ;;	\
		esac;							\
	done
	${INSTALL_DATA} ${WRKSRC:Q}/management/management-notes.txt	\
		${DESTDIR}${DOCDIR:Q}
	cd ${WRKSRC:Q}/sample-config-files; for file in *; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR:Q}/config;	\
	done
	cd ${WRKSRC:Q}/sample-scripts; for file in *; do		\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR:Q}/scripts;	\
	done
	cd ${WRKSRC:Q}/sample-keys; for file in *; do			\
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR:Q}/keys;	\
	done

.include "../../mk/bsd.pkg.mk"
