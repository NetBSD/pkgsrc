# $NetBSD: Makefile,v 1.20 2005/03/24 21:12:58 wiz Exp $

DISTNAME=	team-3.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Portable multi-buffered tape streaming utility

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=	${WRKDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall) \
		${ECHO} man/cat1/team.0 >>${PLIST_SRC}; \
		;; \
	    maninstall) \
		${ECHO} man/man1/team.1 >>${PLIST_SRC}; \
		;; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
