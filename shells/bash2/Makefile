# $NetBSD: Makefile,v 1.39 2002/11/26 09:39:10 jlam Exp $
#

DISTNAME=	bash-2.05b
PKGNAME=	bash-2.05.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

# bash is needed to bootstrap buildlink2 on Darwin.
USE_BUILDLINK2=		no

GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'

PKG_SHELL=		${PREFIX}/bin/bash

.include "../../mk/bsd.prefs.mk"

.if defined(BASH_STATIC) && ${BASH_STATIC} == YES
CONFIGURE_ARGS+=	--enable-static-link
.endif

GETTEXTDIR=		${WRKDIR}/.gettext
.if exists(/usr/include/libintl.h)
GETTEXT_PREFIX=		/usr
.else
DEPENDS+=		gettext-lib>=0.10.35nb1:../../devel/gettext-lib
EVAL_PREFIX+=		GETTEXT_PREFIX=gettext-lib
GETTEXT_PREFIX_DEFAULT=	${LOCALBASE}
.endif

# Remove -I$(includedir) from the INCLUDES passed to the compiler.  We
# want the build to be completely self-contained.
#
pre-build:
	cd ${WRKSRC};							\
	files="Makefile.in";						\
	for file in $${files}; do					\
		${SED} -e "s|[  ]*-I\$$(includedir)||"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

# Symlink the correct gettext libraries and headers into a private directory
# that is placed in the library and header search paths.
#
pre-configure:
	cd ${GETTEXT_PREFIX};						\
	for file in include/libintl.h lib/libintl.*; do			\
		if [ -f "$${file}" ]; then				\
			${MKDIR} ${GETTEXTDIR}/`${DIRNAME} $${file}`;	\
			${LN} -sf ${GETTEXT_PREFIX}/$${file}		\
				${GETTEXTDIR}/$${file};			\
		fi;							\
	done

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

CPPFLAGS:=	-I${GETTEXTDIR}/include ${CPPFLAGS}
CFLAGS:=	-I${GETTEXTDIR}/include ${CFLAGS}
LDFLAGS=	# empty
LIBINTL_LIST!=	set ${GETTEXT_PREFIX}/lib/libintl.*; ${ECHO} $$1
.if ${LIBINTL_LIST} != "${GETTEXT_PREFIX}/lib/libintl.*"
LDFLAGS+=	-L${GETTEXTDIR}/lib
.if ${_USE_RPATH} == "yes"
LDFLAGS+=	-Wl,-R${GETTEXT_PREFIX}/lib
.endif
LIBS+=		${LDFLAGS} -lintl
.endif
