# $NetBSD: Makefile,v 1.5 2008/11/22 00:20:58 he Exp $

DISTNAME=	XML-AutoWriter-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-AutoWriter/
COMMENT=	DOCTYPE-driven valid XML output

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/AutoWriter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
