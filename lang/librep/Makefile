# $NetBSD: Makefile,v 1.32 2004/01/24 13:51:14 grant Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.16.1
#PKGREVISION=		3
PKGREVISION=		1
CATEGORIES=		lang devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librep/}

MAINTAINER=		danw@NetBSD.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

DEPENDS+=		libtool-base>=${LIBTOOL_REQD}:../../devel/libtool-base

USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_BUILDLINK2=		# defined
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
REP_LIBTOOL=		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ARGS+=	--enable-static

USE_MAKEINFO=	YES
INFO_FILES=	librep.info

PLIST_SUBST+=		REP_VERS=${REP_VERS}

post-install:
	${RM} -f ${REP_LIBTOOL}
	${LN} -sf ${LIBTOOL} ${REP_LIBTOOL}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
