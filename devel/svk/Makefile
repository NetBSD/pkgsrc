# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:33 tv Exp $

DISTNAME=	SVK-0.21
PKGNAME=	svk-0.21
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://svk.elixus.org/
COMMENT=	A decentralized version control system built on Subversion

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVK/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion
DEPENDS+=	p5-Algorithm-Annotate>=0.10:../../devel/p5-Algorithm-Annotate
DEPENDS+=	p5-Compress-Zlib>=1.33:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Data-Hierarchy>=0.19:../../devel/p5-Data-Hierarchy
DEPENDS+=	p5-File-BaseDir>=0.02:../../devel/p5-File-BaseDir
DEPENDS+=	p5-File-MimeInfo>=0.10:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-IO-Digest>=0.10:../../devel/p5-IO-Digest
DEPENDS+=p5-Locale-Maketext-Lexicon>=0.42:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=p5-Locale-Maketext-Simple>=0.12:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-PerlIO-via-dynamic>=0.11:../../devel/p5-PerlIO-via-dynamic
DEPENDS+=	p5-PerlIO-via-symlink>=0.01:../../devel/p5-PerlIO-via-symlink
DEPENDS+=	p5-Pod-Escapes>=1.04:../../textproc/p5-Pod-Escapes
DEPENDS+=	p5-Pod-Simple>=3.02:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-Regexp-Shellish>=0.93:../../devel/p5-Regexp-Shellish
DEPENDS+=	p5-SVN-Mirror>=0.47:../../devel/p5-SVN-Mirror
DEPENDS+=	p5-SVN-Simple>=0.25:../../devel/p5-SVN-Simple
DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

.include "../../databases/shared-mime-info/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
