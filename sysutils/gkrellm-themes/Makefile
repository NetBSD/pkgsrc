# $NetBSD: Makefile,v 1.1 2021/11/27 09:32:09 pho Exp $
DISTNAME=	GKrellM-Skins
PKGNAME=	gkrellm-themes-2003.01.29
CATEGORIES=	sysutils
MASTER_SITES=	http://www.muhri.net/gkrellm/
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/GKrellM-skins

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muhri.net/gkrellm/
COMMENT=	Collection of themes for GKrellM
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	chmod find tar pax bash:run
NO_BUILD=	yes

post-extract:
# Remove duplicate tarballs.
	${RUN}for file in aliens.tgz cyrus.gkrellm.tar.gz glass.gkrellm.tar.gz IReX.tar.gz; do \
		${RM} "${WRKSRC}/$$file"; \
	done
# Extract tarballs here, so that REPLACE_BASH can do its job in the
# pre-configure stage.
	${RUN}${MKDIR} "${WRKDIR}/dist"
	${RUN}cd "${WRKSRC}" && for file in *gz; do \
		${STEP_MSG} "Extracting $$file"; \
		${TAR} -zxf "$$file" -C "${WRKDIR}/dist" \
			--exclude "CVS" \
			--exclude "*~" \
			--exclude "*.orig" \
			--exclude "*.swp" \
			--exclude ".xvpics" \
			--no-same-owner \
			--no-same-permissions; \
	done
# Fix inappropriate permissions. Some directories are 777 and some
# non-executable files are 755.
	${RUN}${STEP_MSG} "Fixing permission bits"
	${RUN}${FIND} "${WRKDIR}/dist" -type d -exec ${CHMOD} 0755 {} +
	${RUN}${FIND} "${WRKDIR}/dist" \
		${REPLACE_BASH:@file@\( -path "${file}" -prune \) -or @} \
		-type f -exec ${CHMOD} 0644 {} +

REPLACE_BASH+=	${WRKDIR}/dist/BloeStolen/convert
REPLACE_BASH+=	${WRKDIR}/dist/twilite/change_colors

INSTALLATION_DIRS+=	share/gkrellm2/themes
do-install:
	${RUN}cd "${WRKDIR}/dist" && for dir in *; do \
		${STEP_MSG} "Installing $$dir"; \
		${PAX} -wr "$$dir" ${DESTDIR}${PREFIX}/share/gkrellm2/themes; \
	done

.include "../../mk/bsd.pkg.mk"
