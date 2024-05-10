# $NetBSD: buildlink3.mk,v 1.1 2024/05/10 06:00:16 wiz Exp $

BUILDLINK_TREE+=	mariadb-embedded

.if !defined(MARIADB_EMBEDDED_BUILDLINK3_MK)
MARIADB_EMBEDDED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-embedded+=	mariadb-embedded>=10.11.7
BUILDLINK_PKGSRCDIR.mariadb-embedded?=		../../databases/mariadb1011-embedded

#.include "../../archivers/bzip2/buildlink3.mk"
#.include "../../archivers/xz/buildlink3.mk"
#.include "../../databases/mariadb1011-client/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../archivers/bzip2/buildlink3.mk"
#.include "../../archivers/zstd/buildlink3.mk"
#.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/mariadb1011-client/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../textproc/fmtlib/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
.endif	# MARIADB_EMBEDDED_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-embedded
