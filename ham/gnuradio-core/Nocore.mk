# $NetBSD: Nocore.mk,v 1.7 2015/09/01 04:13:43 mef Exp $

DEPENDS+=	gnuradio-core-[0-9]*:../../ham/gnuradio-core

# Default list for reducing PLIST
# gnuradio-* names to be common (to get the list to reduce)
PLIST_MINUS=	core

# Remove the same files gnuradio-core installs
# Do a part of PLIST_SUBST and remove non real file listings
#.if empty(PKGBASE:Mgnuradio-core) && !empty(PLIST_MINUS)
post-install:
# Take care CONF_FILES stuff
#	${MV}		    ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
#			    ${DESTDIR}${PREFIX}/${EGDIR}/
	for i in ${PLIST_MINUS} ; do				\
	  for p in PLIST PLIST.oss PLIST.${OPSYS} ; do		\
	    f="${PKGDIR}/../../ham/gnuradio-$${i}/$${p}";	\
	    if [ -f "$${f}" ]; then				\
	      ${SED} -e 's,$${PYSITELIB},${PYSITELIB},'		\
	       -e 's,$${PKGVERSION},${PKGVERSION_NOREV},'	\
	       -e '/^@comment/d'				\
	       -e '/^@pkgdir/d'					\
	       "$${f}";						\
	    fi							\
	  done							\
	done							\
	| ${AWK} ${_PLIST_SHLIB_AWK}				\
	> ${WRKDIR}/.PLIST.minus;
	(cd ${WRKDIR}/.destdir/${PREFIX};			\
	${RM} -f $$(cat ${WRKDIR}/.PLIST.minus)	);
