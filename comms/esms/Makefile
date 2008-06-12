# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:16 joerg Exp $

DISTNAME=	esms-0.9.5
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://esms.sourceforge.net/
COMMENT=	Command line SMS send tool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree>=3.11:../../www/p5-HTML-Tree

GNU_CONFIGURE=	YES

USE_TOOLS+=	perl:run
REPLACE_PERL=	esms

.include "../../mk/bsd.pkg.mk"
