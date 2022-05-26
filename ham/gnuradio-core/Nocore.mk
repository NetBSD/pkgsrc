# $NetBSD: Nocore.mk,v 1.10 2022/05/26 15:20:09 mef Exp $

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
#       ------------------------------------------------------------
#       Generate the file .PLIST.minus  (note: it is before PLIST_SUBST applies)
#       ------------------------------------------------------------
	for i in ${PLIST_MINUS} ; do				\
	  for p in PLIST PLIST.oss PLIST.${OPSYS} ; do		\
	    f="${PKGDIR}/../../ham/gnuradio-$${i}/$${p}";	\
	    if [ -f "$${f}" ]; then				\
	      ${SED} -e 's,$${PYSITELIB},${PYSITELIB},'		\
	       -e 's,$${PKGVERSION},${PKGVERSION_NOREV},'	\
	       -e 's,$${PKGVER_MICRO},${PKGVER_MICRO},'		\
	       -e '/^@comment/d'				\
	       -e '/^@pkgdir/d'					\
	       "$${f}";						\
	    fi							\
	  done							\
	done							\
	| ${PKGSRC_SETENV} ${_PLIST_AWK_ENV} ${AWK} ${_PLIST_SHLIB_AWK}				\
	> ${WRKDIR}/.PLIST.minus;
#       ------------------------------------------------------------
#       And then remove the files listed in .PLIST.minus
#       ------------------------------------------------------------
	(cd ${WRKDIR}/.destdir/${PREFIX};		\
	${RM} -f $$(cat ${WRKDIR}/.PLIST.minus)	;	\
	${RM} -f lib/libaudio.so.*		;	\
	${RM} -f lib/libgnuradio-analog.so.*	;	\
	${RM} -f lib/libgnuradio-blocks.so.*	;	\
	${RM} -f lib/libgnuradio-filter.so.* 	;	\
	${RM} -f lib/libgnuradio-fft.so.*    	;	\
	${RM} -f lib/libgnuradio-pmt.so.*	;	\
	${RM} -f lib/libgnuradio-runtime.so.*	;	\
	${RM} -f lib/libgnuradio-audio.so.* 	; 	)
# workaround for gnuradio-doxygen
#  (the same target can't be set on gnuradio-doxygen side
#
	(cd ${WRKDIR}/.destdir/${PREFIX};			\
	${RM} -f share/doc/gnuradio-${PKGVERSION}/html/_formulas.aux; \
	${RM} -f share/doc/gnuradio-${PKGVERSION}/html/_formulas.log; \
	${RM} -f share/doc/gnuradio-${PKGVERSION}/html/_formulas.dvi; \
	)
