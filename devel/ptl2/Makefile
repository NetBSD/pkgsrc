# $NetBSD: Makefile,v 1.32 2001/04/30 04:16:09 jlam Exp $

DISTNAME=		PTL-2.1.7
PKGNAME=		ptl-2.1.7
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.media.osaka-cu.ac.jp/pub/PTL/PTL2/

PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		msaitoh@netbsd.org
HOMEPAGE=		http://www.media.osaka-cu.ac.jp/~k-abe/PTL/
COMMENT=		Portable user-level Thread Library 2 written by Kota Abe

BUILD_DEPENDS=		perl>=${PERL5_REQD}:../../lang/perl5

MAKE_ENV=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"
PLIST_SRC=		${WRKDIR}/PLIST

post-install:
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/PTL/include
	@${FIND} ${PREFIX}/PTL/include -type f -name "*.orig" | xargs ${RM}
	@${FIND} ${PREFIX}/PTL/include -type d -print | xargs ${CHMOD} 755
	@${FIND} ${PREFIX}/PTL/include -type f -print | xargs ${CHMOD} 444
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@cd ${PREFIX}; \
	${FIND} PTL -type f >>${PLIST_SRC}; \
	for LINK in `${FIND} PTL -type l`; do \
	  set - X `${FILE} $$LINK`; \
	  ${ECHO} "@exec ${LN} -s $$6 %D/$$LINK" >>${PLIST_SRC}; \
	  ${ECHO} "@unexec ${RM} -f %D/$$LINK" >>${PLIST_SRC}; \
	done; \
	for DIR in `${FIND} PTL -type d | sort -r`; do \
	  if [ -z "`ls $$DIR`" ]; then \
	    ${ECHO} "@exec ${MKDIR} %D/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	  ${ECHO} "@dirrm $$DIR" >>${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
