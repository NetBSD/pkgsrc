# $NetBSD: Makefile,v 1.17 2011/10/24 05:23:58 hiramatsu Exp $

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	chat perl5
MASTER_SITES=	http://notdoneliving.net/code/Net-Goofey/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notdoneliving.net/code/
COMMENT=	Perl module for communicating with a Goofey server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Goofey/.packlist

# Requires the user to enter a username/password
INTERACTIVE_STAGE=	test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
