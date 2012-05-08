# $NetBSD: hacks.mk,v 1.1 2012/05/08 09:24:15 abs Exp $

.if !defined(OPENJDK7_HACKS_MK)
OPENJDK7_HACKS_MK=	# empty

### Ensure we do not pickup external jpeg includes: openjdk uses an internal
### libjpeg with potentially conflicting defines, which breaks at least
### libjpeg-turbo
post-wrapper:
	${RM} -f ${BUILDLINK_DIR}/include/jconfig.h
	${RM} -f ${BUILDLINK_DIR}/include/jerror.h
	${RM} -f ${BUILDLINK_DIR}/include/jmorecfg.h
	${RM} -f ${BUILDLINK_DIR}/include/jpeglib.h

.endif
