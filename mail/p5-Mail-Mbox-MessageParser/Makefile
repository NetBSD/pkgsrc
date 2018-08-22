# $NetBSD: Makefile,v 1.28 2018/08/22 09:45:31 wiz Exp $

DISTNAME=	Mail-Mbox-MessageParser-1.5111
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-Mbox-MessageParser/
COMMENT=	Perl5 module for parsing mail messages
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-FileHandle-Unget-[0-9]*:../../devel/p5-FileHandle-Unget
DEPENDS+=	lzip>=0:../../archivers/lzip

#DEPENDS+=	{perl>=5.10,p5-Storable-[0-9]*}:../../devel/p5-Storable

BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
BUILD_DEPENDS+=	p5-Test-Compile>=0:../../devel/p5-Test-Compile
BUILD_DEPENDS+=	p5-File-Slurper>=0:../../devel/p5-File-Slurper

PERL5_PACKLIST=		auto/Mail/Mbox/MessageParser/.packlist

USE_TOOLS+=	grep gzip

SETTINGS+=	INSTALLDIRS=site
# XXX: might need adaptation if the programs are not
# in the base system
SETTINGS+=	BZIP=/usr/bin/bzip2
SETTINGS+=	BZIP2=/usr/bin/bzip2
SETTINGS+=	DIFF=/usr/bin/diff
SETTINGS+=	XZ=/usr/bin/xz
SETTINGS+=	CAT=/bin/cat
SETTINGS+=	GZIP=${GZIP_CMD}

MAKE_PARAMS+=	--skipdeps ${SETTINGS}
MAKE_PARAMS+=	</dev/null

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
