# $NetBSD: Makefile,v 1.15 2005/05/09 22:40:52 epg Exp $

DISTNAME=	SVK-1.00
PKGNAME=	${DISTNAME:S/SVK/svk/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://svk.elixus.org/
COMMENT=	A decentralized version control system built on Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVK/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

DEPENDS+=	p5-subversion>=1.0.7:../../devel/p5-subversion
DEPENDS+=	p5-Algorithm-Annotate>=0.10:../../devel/p5-Algorithm-Annotate
DEPENDS+=	p5-Algorithm-Diff>=1.19.01:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone
DEPENDS+=	p5-Compress-Zlib>=1.33:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Data-Hierarchy>=0.21:../../devel/p5-Data-Hierarchy
DEPENDS+=	p5-File-BaseDir>=0.02:../../devel/p5-File-BaseDir
DEPENDS+=	p5-File-Type>=0.22:../../devel/p5-File-Type
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-IO-Digest>=0.10:../../devel/p5-IO-Digest
DEPENDS+=p5-Locale-Maketext-Lexicon>=0.42:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=p5-Locale-Maketext-Simple>=0.12:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-PerlIO-eol>=0.13:../../devel/p5-PerlIO-eol
DEPENDS+=	p5-PerlIO-via-dynamic>=0.11:../../devel/p5-PerlIO-via-dynamic
DEPENDS+=	p5-PerlIO-via-symlink>=0.02:../../devel/p5-PerlIO-via-symlink
DEPENDS+=	p5-Pod-Escapes>=1.04:../../textproc/p5-Pod-Escapes
DEPENDS+=	p5-Pod-Simple>=3.02:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-Regexp-Shellish>=0.93:../../devel/p5-Regexp-Shellish
DEPENDS+=	p5-SVN-Mirror>=0.58:../../devel/p5-SVN-Mirror
DEPENDS+=	p5-SVN-Simple>=0.27:../../devel/p5-SVN-Simple
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-YAML>=0.38:../../textproc/p5-YAML
DEPENDS+=	p5-Class-Autouse>=1.15:../../devel/p5-Class-Autouse

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
