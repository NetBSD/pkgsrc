# $NetBSD: Makefile,v 1.28 2012/08/03 13:07:54 adam Exp $

DISTNAME=	grep-2.13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		makeinfo msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl-regexp
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		MKDIR_P=${INSTALL_DATA_DIR:Q}
INFO_FILES=		yes
TEXINFO_REQD=		4.0

INSTALLATION_DIRS=	gnu/bin gnu/man/man1

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
