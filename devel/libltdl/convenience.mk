# $NetBSD: convenience.mk,v 1.3 2004/11/05 17:31:28 tv Exp $
#
# Override "libltdlc.la" -- the libltdl "convenience" library embedded into
# programs that ship with libltdl.  Also override packages attempting to
# build and install the full "libltdl.la".

post-patch: fix-libltdlc
fix-libltdlc:
	${ECHO} 'all install clean:' >${WRKSRC}/libltdl/Makefile.in
	${ECHO} 'all install clean:' >${WRKSRC}/libltdl/Makefile
	${RM} -f ${WRKSRC}/libltdl/Makefile.am ${WRKSRC}/libltdl/configure*
	${LN} -fs ${BUILDLINK_DIR}/include/ltdl.h ${WRKSRC}/libltdl/ltdl.h
	${LN} -fs ${BUILDLINK_DIR}/lib/libltdl.la ${WRKSRC}/libltdl/libltdl.la
	${LN} -fs ${BUILDLINK_DIR}/lib/libltdl.la ${WRKSRC}/libltdl/libltdlc.la

.include "../../devel/libltdl/buildlink3.mk"
