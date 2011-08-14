# $NetBSD: Makefile,v 1.16 2011/08/14 13:25:26 obache Exp $

DISTNAME=	Mail-Mbox-MessageParser-1.5002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-Mbox-MessageParser/
COMMENT=	Perl5 module for parsing mail messages
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-FileHandle-Unget-[0-9]*:../../devel/p5-FileHandle-Unget
DEPENDS+=	{perl>=5.10,p5-Storable-[0-9]*}:../../devel/p5-Storable

BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Mail/Mbox/MessageParser/.packlist

USE_TOOLS+=	grep gzip

SETTINGS+=	INSTALLDIRS=site
# XXX: might need adaptation if the programs are not
# in the base system
SETTINGS+=	BZIP=/usr/bin/bzip2
SETTINGS+=	BZIP2=/usr/bin/bzip2
SETTINGS+=	DIFF=/usr/bin/diff
SETTINGS+=	GZIP=${GZIP_CMD}

MAKE_PARAMS+=	--skipdeps ${SETTINGS}
MAKE_PARAMS+=	</dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
