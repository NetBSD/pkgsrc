# $NetBSD: Makefile,v 1.9 2002/01/29 21:09:27 jlam Exp $
#

DISTNAME=	Linux-${PKGNAME}
PKGNAME=	PAM-0.75
CATEGORIES=	security
MASTER_SITES=	http://www.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.kernel.org/pub/linux/libs/pam/pre/library/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kernel.org/pub/linux/libs/pam/
COMMENT=	Pluggable Authentication Modules

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-sconfigdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-static-libpam

CFLAGS+=		-DHAVE_UTMP_H=1
CFLAGS+=		-fpic -fPIC
MAKE_FLAGS+=		OS_CFLAGS="${CFLAGS}"

PKG_SYSCONFSUBDIR?=	pam
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
HTMLDIR=		${PREFIX}/share/doc/html/${PKGBASE}

CFILES=			access.conf pam_env.conf group.conf time.conf
CONF_FILES=		${EGDIR}/pam.conf ${PKG_SYSCONFBASE}/pam.conf
.for FILE in ${CFILES}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

post-extract:
	cd ${WRKSRC}/doc;						\
	if [ -f ${DISTNAME}-docs.tar.gz ]; then				\
		${GZCAT} ${DISTNAME}-docs.tar.gz | ${GTAR} -xf -;	\
	fi

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/pam.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_access/access.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_env/pam_env.conf-example	\
		${EGDIR}/pam_env.conf
	${INSTALL_DATA} ${WRKSRC}/modules/pam_group/group.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_time/time.conf ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in modules/*.sgml; do		\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; for file in html/*.html; do			\
		${INSTALL_DATA} $${file} ${HTMLDIR};			\
	done

.include "../../security/libcrack/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
