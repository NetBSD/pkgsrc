# $NetBSD: convenience.mk,v 1.4 2004/11/15 12:19:40 sketch Exp $
#
# Override "libltdlc.la" -- the libltdl "convenience" library embedded into
# programs that ship with libltdl.  Also override packages attempting to
# build and install the full "libltdl.la".

post-patch: fix-libltdlc
fix-libltdlc:
	${ECHO} 'all install clean:' >${WRKSRC}/libltdl/Makefile.in
	${ECHO} 'all install clean:' >${WRKSRC}/libltdl/Makefile
	${RM} -f ${WRKSRC}/libltdl/Makefile.am ${WRKSRC}/libltdl/configure*
	${RM} -f ${WRKSRC}/libltdl/ltdl.h
	${LN} -s ${BUILDLINK_DIR}/include/ltdl.h ${WRKSRC}/libltdl/ltdl.h
	${RM} -f ${WRKSRC}/libltdl/libltdl.la
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.la ${WRKSRC}/libltdl/libltdl.la
	${RM} -f ${WRKSRC}/libltdl/libltdlc.la
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.la ${WRKSRC}/libltdl/libltdlc.la

.include "../../devel/libltdl/buildlink3.mk"
