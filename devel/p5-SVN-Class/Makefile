# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:34 obache Exp $

DISTNAME=	SVN-Class-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Class/
COMMENT=	Manipulate Subversion workspaces with Perl objects
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	{perl>=5.1,p5-IPC-Cmd>=0.40}:../../devel/p5-IPC-Cmd
DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Path-Class-File-Stat-[0-9]*:../../devel/p5-Path-Class-File-Stat
DEPENDS+=	p5-Rose-Object-[0-9]*:../../devel/p5-Rose-Object
DEPENDS+=	p5-Rose-URI-[0-9]*:../../www/p5-Rose-URI
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

PERL5_PACKLIST=		auto/SVN/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
