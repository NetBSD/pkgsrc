# $NetBSD: buildlink2.mk,v 1.9 2004/01/01 21:10:05 wiz Exp $

.if !defined(DB_BUILDLINK2_MK)
DB_BUILDLINK2_MK=	# defined

BUILDLINK_DEPENDS.db?=		db>=2.7.3
BUILDLINK_PKGSRCDIR.db?=	../../databases/db

_NEED_DB2=			YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_DB185)
.  if exists(/usr/include/db.h)		# NetBSD, Darwin
# See if /usr/include/db.h belongs to db3 or db4
_IS_DB34!=	${GREP} -c 'DB_VERSION_MAJOR.*[34]$$' /usr/include/db.h || ${TRUE}
.    if ${_IS_DB34} == "0"
BUILDLINK_PREFIX.db=		/usr
BUILDLINK_FILES.db=		include/db.h
BUILDLINK_FILES.db+=		include/mpool.h
BUILDLINK_CPPFLAGS.db=		# empty
BUILDLINK_LDFLAGS.db=		# empty
BUILDLINK_LIBS.db=		# empty
_NEED_DB2=			NO
.    endif
.  elif exists(/usr/include/db1/db.h)
# Linux
BUILDLINK_PREFIX.db=		/usr
BUILDLINK_FILES.db=		include/db1/*
BUILDLINK_CPPFLAGS.db=		-I${BUILDLINK_PREFIX.db}/include/db1
BUILDLINK_LDFLAGS.db=		# empty
BUILDLINK_LIBS.db=		-ldb1
BUILDLINK_TRANSFORM+=		l:db:db1
_NEED_DB2=			NO
.  endif
.endif

.if ${_NEED_DB2} == "YES"
BUILDLINK_PACKAGES+=		db
EVAL_PREFIX+=			BUILDLINK_PREFIX.db=db
BUILDLINK_PREFIX.db_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.db=		include/db2/*
BUILDLINK_FILES.db+=		lib/libdb2.*
BUILDLINK_CPPFLAGS.db=		-I${BUILDLINK_PREFIX.db}/include/db2
BUILDLINK_LDFLAGS.db=		-L${BUILDLINK_PREFIX.db}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.db}/lib
BUILDLINK_LIBS.db=		-ldb2
BUILDLINK_TRANSFORM+=		l:db:db2
.endif
CPPFLAGS+=			${BUILDLINK_CPPFLAGS.db}

BUILDLINK_TARGETS+=	db-buildlink

db-buildlink: _BUILDLINK_USE

.endif	# DB_BUILDLINK2_MK
