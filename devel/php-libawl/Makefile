# $NetBSD: Makefile,v 1.17 2019/05/10 12:26:34 hauke Exp $
#

DISTNAME=	libawl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	-https://gitlab.com/davical-project/awl/repository/archive.tar.gz?ref=${GITLAB_TAG}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://gitlab.com/davical-project/awl
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

LIBAWL_VERSION=	0.60
GITLAB_TAG=	r${LIBAWL_VERSION}
GITLAB_REV=	3efb13de38ea4c1cc298f206199848467af18456

pre-patch:
	${MV} ${WRKDIR}/awl-${GITLAB_TAG}-${GITLAB_REV} ${WRKSRC}

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
