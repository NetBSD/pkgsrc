# $NetBSD: Makefile,v 1.44 2003/12/06 18:26:36 wiz Exp $

DISTNAME=		autoconf-2.59
CATEGORIES=		devel
# 2.59 not uploaded to GNU site; change back to GNU mirrors
# during next update
MASTER_SITES=		http://www.lrde.epita.fr/~akim/download/
#MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts

DEPENDS=		m4>=1.4:../../devel/m4

# The next line is for conflicts with old versions of this package,
# which had autoconf-devel as PKGNAME.
CONFLICTS=		autoconf-devel-[0-9]*

USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-lispdir
CONFIGURE_ENV+=		AWK="${AWK}"
M4=			${PREFIX}/bin/gm4

INFO_FILES=		autoconf.info standards.info

PERL5_REQD=		5.6
TEXINFO_REQD=		4.0

AUTOMAKE_OVERRIDE=	NO

TEST_TARGET=		check

# undo a rather stupid hack in the install step when --without-lispdir is used
post-install:
	${RM} -rf ${WRKSRC}/lib/emacs/no

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
