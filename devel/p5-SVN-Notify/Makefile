# $NetBSD: Makefile,v 1.7 2008/10/19 19:18:00 he Exp $

DISTNAME=	SVN-Notify-2.77
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Notify/
COMMENT=	Perl module for mailing messages for Subversion repository activity

PERL5_PACKLIST=		auto/SVN/Notify/.packlist
PERL5_MODULE_TYPE=	Module::Build
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
