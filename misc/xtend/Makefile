# $NetBSD: Makefile,v 1.5 2010/02/04 16:50:32 joerg Exp $
#

DISTNAME=	xtend-1.2beta4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.jabberwocky.com/pub/xtend/

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://www.jabberwocky.com/software/xtend/
COMMENT=	Monitors X10 commands using heyu to automate UNIX functions

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	heyu>=1.35:../../misc/heyu

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
