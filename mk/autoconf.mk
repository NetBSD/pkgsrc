# $NetBSD: autoconf.mk,v 1.5 2004/10/07 02:01:38 jlam Exp $
#
# makefile fragment for packages that use autoconf
# AUTOCONF_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate autoconf package
# and sets the following variables:
#	AUTOCONF:	autoconf binary to use
#	AUTORECONF:	autoreconf binary to use
#	AUTOHEADER:	autoheader binary to use
#

.if !defined(AUTOCONF_MK)
AUTOCONF_MK=	# defined

# minimal required version
AUTOCONF_REQD?= 2.50

.if empty(AUTOCONF_REQD:M2.1[0-9]*)
BUILD_DEPENDS+=		autoconf>=${AUTOCONF_REQD}:../../devel/autoconf
AUTOCONF=		${LOCALBASE}/bin/autoconf
AUTORECONF=		${LOCALBASE}/bin/autoreconf
AUTOHEADER=		${LOCALBASE}/bin/autoheader
.else
BUILD_DEPENDS+=		autoconf213>=${AUTOCONF_REQD}:../../devel/autoconf213
AUTOCONF=		${LOCALBASE}/bin/autoconf-2.13
AUTORECONF=		${LOCALBASE}/bin/autoreconf-2.13
AUTOHEADER=		${LOCALBASE}/bin/autoheader-2.13
.  if defined(USE_LIBTOOL)
pre-configure: do-libtool-m4-override
.  endif
.endif

# LIBTOOL_M4_OVERRIDE lists the locations where the libtool.m4 symlink
# will be created.  The libtool.m4 is only created if a GNU configure
# script exists at that location.
#
LIBTOOL_M4_OVERRIDE?=	libtool.m4 */libtool.m4 */*/libtool.m4

# Symlink the libtool-1.4.m4 file into any directory in which there's a
# configure script under ${WRKSRC}.  The  symlink is called "libtool.m4",
# which is the name expected by the autoconf tools.  The symlinking is
# only done if ${AUTOCONF_REQD} == 2.13 and USE_LIBTOOL is defined.  This
# allows autoconf-2.13, autoreconf-2.13 and aclocal-2.13 to use the older
# libtool.m4 file when regenerating files.  This is okay, because we later
# override the generated libtool file anyway.
#
.PHONY: do-libtool-m4-override
do-libtool-m4-override:
.for _pattern_ in ${LIBTOOL_M4_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_:S/libtool.m4$/configure/}; do		\
		if [ -f "$$file" ]; then				\
			libtool_m4=`${DIRNAME} $$file`/libtool.m4;	\
			${LN} -sf ${PKGSRCDIR}/mk/gnu-config/libtool-1.4.m4 \
				$$libtool_m4;				\
		fi;							\
	done
.endfor

.endif # AUTOCONF_MK
