# $NetBSD: Makefile,v 1.10 2004/12/20 11:31:10 grant Exp $

DISTNAME=	XML-Checker-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for validating XML

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Checker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
