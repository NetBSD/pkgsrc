# $NetBSD: Makefile,v 1.4 2010/08/21 16:35:02 seb Exp $

DISTNAME=	Email-FolderType-0.813
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-FolderType/
COMMENT=	Perl 5 module to determine the type of a mail folder

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Email/FolderType/.packlist

DEPENDS+=	{perl>=5.10,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
