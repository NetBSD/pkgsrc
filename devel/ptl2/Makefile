# $NetBSD: Makefile,v 1.44 2004/04/27 03:09:58 snj Exp $

DISTNAME=		PTL-2.1.9
PKGNAME=		ptl-2.1.9
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.media.osaka-cu.ac.jp/pub/PTL/PTL2/

PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		msaitoh@NetBSD.org
HOMEPAGE=		http://www.media.osaka-cu.ac.jp/~k-abe/PTL/
COMMENT=		Portable user-level Thread Library 2 written by Kota Abe

USE_BUILDLINK3=		YES
USE_PERL5=		build
MAKE_ENV=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"
PLIST_SRC=		${WRKDIR}/PLIST

post-install:
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/PTL/include
	@${FIND} ${PREFIX}/PTL/include -type f -name "*.orig" -print | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/PTL/include -type d -print | ${XARGS} ${CHMOD} 755
	@${FIND} ${PREFIX}/PTL/include -type f -print | ${XARGS} ${CHMOD} 444
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@cd ${PREFIX}; \
	${FIND} PTL -type f -print >>${PLIST_SRC}; \
	for LINK in `${FIND} PTL -type l -print`; do \
	  set - X `${FILE_CMD} $$LINK`; \
	  ${ECHO} "@exec ${LN} -s $$6 %D/$$LINK" >>${PLIST_SRC}; \
	  ${ECHO} "@unexec ${RM} -f %D/$$LINK" >>${PLIST_SRC}; \
	done; \
	for DIR in `${FIND} PTL -type d -print | sort -r`; do \
	  if [ -z "`ls $$DIR`" ]; then \
	    ${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	  ${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
