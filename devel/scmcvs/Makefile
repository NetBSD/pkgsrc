# $NetBSD: Makefile,v 1.24 2026/07/04 12:56:29 gdt Exp $

DISTNAME=	cvs-1.12.13
PKGREVISION=	9
CATEGORIES=	devel scm
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/feature/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cvs.nongnu.org/
COMMENT=	Concurrent Versions System
LICENSE=	gnu-gpl-v2

# autoconf 2.73 AC_PROG_CC attempts to set --std=c23, which cvs does not support.
USE_TOOLS+=		autoconf269
USE_TOOLS+=		makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-external-zlib
CONFIGURE_ARGS+=	--with-rsh=ssh
CONFIGURE_ENV+=		PERL=${TOOLS_PERL5}
CONFIGURE_ENV+=		gl_cv_func_getcwd_null=yes
CPPFLAGS.Linux+=	-D_GNU_SOURCE	# fputs_unlocked(3)

CHECK_INTERPRETER_SKIP=	share/cvs/contrib/*
INFO_FILES=		yes
TEXINFO_REQD+=		4.0

CONFIGURE_ARGS.Darwin+=	--enable-case-sensitivity

.include "options.mk"

AUTOCONF_REQD=		2.50
pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
