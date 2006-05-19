# $NetBSD: convenience.mk,v 1.7 2006/05/19 09:12:29 tonio Exp $
#
# Override "libltdlc.la" -- the libltdl "convenience" library embedded into
# programs that ship with libltdl.  Also override packages attempting to
# build and install the full "libltdl.la".

LIBLTDL_CONVENIENCE_SUBDIR?=	libltdl
.include "../../mk/bsd.prefs.mk"

post-patch: fix-libltdlc
fix-libltdlc:
	@${ECHO} 'Fixing libltdl convenience library linkage.'
.for sd in ${LIBLTDL_CONVENIENCE_SUBDIR}
	@cd ${WRKSRC}/${sd} && \
		${ECHO} 'all install clean:' >Makefile.in && \
		${ECHO} 'all install clean:' >Makefile && \
		${RM} -f Makefile.am configure* ltdl.h *.la && \
		${LN} -s ${BUILDLINK_DIR}/include/ltdl.h ltdl.h && \
		${LN} -s ${BUILDLINK_DIR}/lib/libltdl.la libltdl.la && \
		${LN} -s ${BUILDLINK_DIR}/lib/libltdl.la libltdlc.la
.  if ${OPSYS} == "Darwin"
	@cd ${WRKSRC}/${sd} && \
		${LN} -s ${BUILDLINK_DIR}/lib/libltdl.dylib libltdlc.dylib
.  endif
.endfor

.include "../../devel/libltdl/buildlink3.mk"
