# $NetBSD: Makefile,v 1.16 1999/09/08 16:17:24 bad Exp $

DISTNAME=		PTL2-current-990622
PKGNAME=		ptl2-990622
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.media.osaka-cu.ac.jp/pub/PTL/PTL2/PTL2-current-990622/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		PTL2-current-990622-patch-1 \
			PTL2-current-990622-patch-2 \
			PTL2-current-990622-patch-3 \
			PTL2-current-990622-patch-4
PATCH_DIST_STRIP=	-p1

MAINTAINER=		msaitoh@netbsd.org
HOMEPAGE=		http://www.media.osaka-cu.ac.jp/~k-abe/PTL/

BUILD_DEPENDS=		${LOCALBASE}/bin/perl:../../lang/perl5

CONFLICTS=		ptl-current-*

USE_GMAKE=

MAKE_ENV=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"
PLIST_SRC=		${WRKDIR}/PLIST

NOT_FOR_PLATFORM=	*-*-alpha

post-install:
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/PTL/include
	@find ${PREFIX}/PTL/include -type f -name "*.orig" | xargs ${RM}
	@find ${PREFIX}/PTL/include -type d -print | xargs ${CHMOD} 755
	@find ${PREFIX}/PTL/include -type f -print | xargs ${CHMOD} 444
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@cd ${PREFIX}; \
	find PTL -type f >>${PLIST_SRC}; \
	for LINK in `find PTL -type l`; do \
	  set - X `file $$LINK`; \
	  ${ECHO} "@exec ln -s $$6 %D/$$LINK" >>${PLIST_SRC}; \
	  ${ECHO} "@unexec ${RM} -f %D/$$LINK" >>${PLIST_SRC}; \
	done; \
	for DIR in `find PTL -type d | sort -r`; do \
	  if [ -z "`ls $$DIR`" ]; then \
	    ${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	  ${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
