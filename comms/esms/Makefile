# $NetBSD: Makefile,v 1.7 2005/07/16 01:19:07 jlam Exp $

DISTNAME=	esms-0.9.5
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esms/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://esms.sourceforge.net/
COMMENT=	Command line SMS send tool

DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree>=3.11:../../www/p5-HTML-Tree

GNU_CONFIGURE=	YES

USE_TOOLS+=	perl:run
PERL5_REQD+=	5.6.1
REPLACE_PERL=	esms

.include "../../mk/bsd.pkg.mk"
