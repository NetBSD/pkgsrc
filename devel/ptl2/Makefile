# $NetBSD: Makefile,v 1.8 1999/05/06 22:38:08 tv Exp $

DISTNAME=	PTL2-current-990325
PKGNAME=	ptl2-990325
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.media.osaka-cu.ac.jp/pub/PTL/PTL2/PTL2-current-990325/

MAINTAINER=	msaitoh@netbsd.org
HOMEPAGE=	http://www.media.osaka-cu.ac.jp/~k-abe/PTL/

BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

CONFLICTS=	ptl-current-*

USE_GMAKE=	YES

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
PLIST_SRC=	${WRKDIR}/PLIST

NOT_FOR_ARCHS=	alpha

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
	  ${ECHO} "@unexec rm -f %D/$$LINK" >>${PLIST_SRC}; \
	done; \
	for DIR in `find PTL -type d | sort -r`; do \
	  if [ -z "`ls $$DIR`" ]; then \
	    ${ECHO} "@exec mkdir -p %D/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	  ${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
