# $NetBSD: Makefile,v 1.20 2000/06/07 04:28:20 msaitoh Exp $

DISTNAME=		PTL-2.1.3
PKGNAME=		ptl-2.1.3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.media.osaka-cu.ac.jp/pub/PTL/PTL2/

PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		msaitoh@netbsd.org
HOMEPAGE=		http://www.media.osaka-cu.ac.jp/~k-abe/PTL/

BUILD_DEPENDS=		${LOCALBASE}/bin/perl:../../lang/perl5

MAKE_ENV=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"
PLIST_SRC=		${WRKDIR}/PLIST

NOT_FOR_PLATFORM=	*-*-alpha

post-install:
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/PTL/include
	@${FIND} ${PREFIX}/PTL/include -type f -name "*.orig" | xargs ${RM}
	@${FIND} ${PREFIX}/PTL/include -type d -print | xargs ${CHMOD} 755
	@${FIND} ${PREFIX}/PTL/include -type f -print | xargs ${CHMOD} 444
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@cd ${PREFIX}; \
	${FIND} PTL -type f >>${PLIST_SRC}; \
	${FIND} PTL -type l >>${PLIST_SRC}; \
	for DIR in `${FIND} PTL -type d | sort -r`; do \
	  if [ -z "`ls $$DIR`" ]; then \
	    ${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	  ${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
