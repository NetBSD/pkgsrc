# $NetBSD: Makefile,v 1.32.2.3 2002/06/30 14:30:37 jlam Exp $
#

V=		2.05
DV=		2.05
DISTNAME=	bash-${V}
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://slc2.ins.cwru.edu/pub/dist/
DISTFILES=      bash-${V}.tar.gz bash-doc-${DV}.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

# bash is needed to bootstrap buildlink2 on Darwin.
USE_BUILDLINK2=		no

GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'

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
post-patch:
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
		${MKDIR} ${GETTEXTDIR}/`${DIRNAME} $${file}`;		\
		${LN} -sf ${GETTEXT_PREFIX}/$${file} ${GETTEXTDIR}/$${file}; \
	done

post-install:
	${TOUCH} /etc/shells
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak || ${TRUE}; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bash
	${INSTALL_MAN} \
		${WRKDIR}/doc/bash.html  \
		${WRKDIR}/doc/bashref.html  \
		${PREFIX}/share/doc/html/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

CPPFLAGS:=	-I${GETTEXTDIR}/include ${CPPFLAGS}
CFLAGS:=	-I${GETTEXTDIR}/include ${CFLAGS}
LDFLAGS=	-L${GETTEXTDIR}/lib
.if ${_USE_RPATH} == "yes"
LDFLAGS+=	-Wl,-R${GETTEXT_PREFIX}/lib
.endif
LIBS+=		${LDFLAGS} -lintl
