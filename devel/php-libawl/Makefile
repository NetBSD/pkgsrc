# $NetBSD: Makefile,v 1.12 2016/06/06 15:14:45 hauke Exp $
#

DISTNAME=	${PHP_PKG_PREFIX}-libawl-${LIBAWL_VERSION}
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
