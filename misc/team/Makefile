# $NetBSD: Makefile,v 1.16 2001/02/17 18:09:27 wiz Exp $
# FreeBSD Id: Makefile,v 1.6 1997/04/30 03:18:06 asami Exp
#

DISTNAME=	team-3.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Portable multi-buffered tape streaming utility

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=	${WRKDIR}/PLIST

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
