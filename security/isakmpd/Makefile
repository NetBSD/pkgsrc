# $NetBSD: Makefile,v 1.11 2000/11/25 23:51:17 kim Exp $
#

DISTNAME=		isakmpd-000915-snap
PKGNAME=		isakmpd-20000915
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.appli.se/pub/isakmpd/

MAINTAINER=		itojun@kame.net

DEPENDS+=		gmp-*:../../devel/gmp

USE_SSL=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

ALL_TARGET=		depend all

PLIST_SRC=		${WRKDIR}/PLIST

MANCOMPRESSED=		${MANZ}

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall) \
		${CAT} ${PKGDIR}/PLIST.cat >> ${PLIST_SRC}; \
		;; \
	    maninstall) \
		${CAT} ${PKGDIR}/PLIST.man >> ${PLIST_SRC}; \
		;; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
