# $NetBSD: Makefile,v 1.3 1999/11/25 19:46:19 tron Exp $

DISTNAME=		spegla-1.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.luth.se/pub/unix/mirror/ \
			ftp://subzero.campus.luth.se/pub/spegla/

MAINTAINER=		jnilsson@ludd.luth.se

MANCOMPRESSED_IF_MANZ=	yes
PLIST_SRC=		${WRKDIR}/PLIST

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} x; do \
	  case $$OPT in \
	    catinstall) ${ECHO} man/cat1/spegla.0 >>${PLIST_SRC};; \
	    maninstall) ${ECHO} man/man1/spegla.1 >>${PLIST_SRC};; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
