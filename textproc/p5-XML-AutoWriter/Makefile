# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:50 joerg Exp $

DISTNAME=	XML-AutoWriter-0.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-ValidWriter/
COMMENT=	DOCTYPE-driven valid XML output

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/AutoWriter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
