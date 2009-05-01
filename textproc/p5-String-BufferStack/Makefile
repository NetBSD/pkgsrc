# $NetBSD: Makefile,v 1.2 2009/05/01 20:58:38 sno Exp $

DISTNAME=	String-BufferStack-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-BufferStack/
COMMENT=	Perl 5 module for nested buffers for templating systems
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/String/BufferStack/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
