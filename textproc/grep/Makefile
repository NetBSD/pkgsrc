# $NetBSD: Makefile,v 1.27 2012/06/01 19:47:46 cheusov Exp $
#

DISTNAME=	grep-2.5.3
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-perl-regexp
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		makeinfo msgfmt
INFO_FILES=		yes
TEXINFO_REQD=		4.0
CONFIGURE_ENV+=		MKDIR_P=${INSTALL_DATA_DIR:Q}

INSTALLATION_DIRS=	gnu/bin gnu/man/man1

CONFIGURE_ARGS+=	--program-prefix=g

post-install:
.for g n in  bin/ggrep gnu/bin/grep   bin/gegrep gnu/bin/egrep \
             bin/gfgrep gnu/bin/fgrep   \
             man/man1/ggrep.1 gnu/man/man1/grep.1 \
             man/man1/ggrep.1 gnu/man/man1/egrep.1 \
             man/man1/ggrep.1 gnu/man/man1/fgrep.1
	${LN} -sf ${PREFIX}/${g} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
