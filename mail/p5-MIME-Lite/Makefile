# $NetBSD: Makefile,v 1.13 2008/10/19 19:18:20 he Exp $

DISTNAME=		MIME-Lite-3.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5mil
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl5 module for simple creation of MIME email messages

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
