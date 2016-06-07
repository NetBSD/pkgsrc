# $NetBSD: Makefile,v 1.13 2016/06/07 17:55:51 joerg Exp $
#

DISTNAME=	libawl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
LIBAWL_VERSION=	0.56
CATEGORIES=	devel
MASTER_SITES=	-https://gitlab.com/davical-project/awl/repository/archive.tar.gz?ref=r${LIBAWL_VERSION}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://gitlab.com/davical-project/awl
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

WRKSRC=		${WRKDIR}/awl-r0.56-9abf998ba0179b9995747c7cc1a848b39cff0b3b

do-install:
	cd ${WRKSRC}/dba;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done;

	cd ${WRKSRC}/inc;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done;

.include "../../devel/php-libawl/Makefile.common"
.include "../../mk/bsd.pkg.mk"
