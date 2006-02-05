# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:04 joerg Exp $

DISTNAME=	XML-Checker-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for validating XML

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Checker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
