# $NetBSD: Makefile,v 1.25 2002/12/23 04:25:01 jlam Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.15.1
PKGREVISION=		3
CATEGORIES=		lang devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librep/}

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

DEPENDS+=		libtool-base>=${LIBTOOL_REQD}:../../devel/libtool-base

USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
REP_LIBTOOL=		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ARGS+=	--enable-static
TEXINFO_OVERRIDE=	YES
TEXINFO_PATTERNS+=	Makedefs.in

PLIST_SUBST+=		REP_VERS=${REP_VERS}

post-install:
	${RM} -f ${REP_LIBTOOL}
	${LN} -sf ${LIBTOOL} ${REP_LIBTOOL}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
