# $NetBSD: Makefile,v 1.5 2002/02/18 15:14:24 seb Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	gawk-3.0.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

INFO_FILES=	gawk.info

GNU_CONFIGURE=	yes

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
