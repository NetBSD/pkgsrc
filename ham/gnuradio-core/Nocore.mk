# $NetBSD: Nocore.mk,v 1.5 2015/01/27 06:03:17 dbj Exp $
# Default list for reducing PLIST
PLIST_MINUS=	core
DEPENDS+=	gnuradio-core-[0-9]*:../../ham/gnuradio-core

# Remove the same files gnuradio-core installs
# Do a part of PLIST_SUBST and remove non real file listings
#.if empty(PKGBASE:Mgnuradio-core) && !empty(PLIST_MINUS)
post-install:
# Take care CONF_FILES stuff
	${MV}		    ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
			    ${DESTDIR}${PREFIX}/${EGDIR}/
	for i in ${PLIST_MINUS} ; do				\
	  for p in PLIST PLIST.${OPSYS} ; do			\
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
