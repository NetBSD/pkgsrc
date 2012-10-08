# $NetBSD: Makefile,v 1.26 2012/10/08 09:57:38 asau Exp $

DISTNAME=	team-3.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Portable multi-buffered tape streaming utility

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

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
