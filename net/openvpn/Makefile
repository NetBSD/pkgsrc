# $NetBSD: Makefile,v 1.10.2.1 2005/11/05 20:17:18 seb Exp $
#

DISTNAME=	openvpn-2.0.5
CATEGORIES=	net
MASTER_SITES=	http://openvpn.net/release/ \
		http://openvpn.net/release/old/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://openvpn.net/
COMMENT=	Easy-to-use SSL VPN daemon

GNU_CONFIGURE=		yes
USE_TOOLS=		grep:run
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_OLD_DES_API=	yes
TEST_TARGET=		check

PKG_SYSCONFSUBDIR=	openvpn
DATADIR=		${PREFIX}/share/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		openvpn

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-password-save
CONFIGURE_ARGS+=	--disable-dependency-tracking

# OpenVPN 2.x has a shared module "plugin" architecture that allows
# inserting callbacks into the server for various tasks.
#
DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-build:
	for file in ${WRKSRC}/easy-rsa/2.0/pkitool; do			\
		${SED}	-e "s|^\(GREP\)=.*|\1=\""${GREP}"\"|"		\
			-e "s|^\(OPENSSL\)=.*|\1=\""${SSLBASE}/bin/openssl"\"|" \
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
		${CHMOD} +x $$file;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}/easy-rsa
	dir=${DATADIR:S/^${PREFIX}\///}/easy-rsa;			\
	cd ${WRKSRC}/easy-rsa/2.0;					\
	${GREP} "^$$dir/" ${PKGDIR}/PLIST | ${SED} "s|^$$dir/||" |	\
	while read file; do						\
		case $$file in						\
		[A-Z]*|*.cnf)	${INSTALL_DATA} $$file ${PREFIX}/$$dir ;; \
		*)		${INSTALL_SCRIPT} $$file ${PREFIX}/$$dir ;; \
		esac;							\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/management/management-notes.txt ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/config
	cd ${WRKSRC}/sample-config-files; for file in *; do		\
		${INSTALL_DATA} $$file ${EGDIR}/config;			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/scripts
	cd ${WRKSRC}/sample-scripts; for file in *; do			\
		${INSTALL_DATA} $$file ${EGDIR}/scripts;		\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/keys
	cd ${WRKSRC}/sample-keys; for file in *; do			\
		${INSTALL_DATA} $$file ${EGDIR}/keys;			\
	done


.include "../../mk/bsd.pkg.mk"
