# $NetBSD: Makefile,v 1.23 2026/07/08 10:56:45 hauke Exp $
#

LIBAWL_VERSION=	0.65
DISTNAME=	libawl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=davical-project/}
GITLAB_PROJECT=	awl
GITLAB_TAG=	r${LIBAWL_VERSION}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://gitlab.com/davical-project/awl
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/awl-${GITLAB_TAG}

USE_TOOLS+=	gmake

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

do-install:
	cd ${WRKSRC}/dba;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done

	cd ${WRKSRC}/inc;					\
	rm *.orig;						\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done

.include "../../devel/php-libawl/Makefile.common"
.include "../../mk/bsd.pkg.mk"
