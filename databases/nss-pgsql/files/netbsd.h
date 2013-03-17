// $NetBSD: netbsd.h,v 1.1.1.1 2013/03/17 14:12:02 asau Exp $

// add necessary functions that is not provided by NetBSD's NSS

#ifndef _NSS_PGSQL_NETBSD_H
#define _NSS_PGSQL_NETBSD_H
enum nss_status {
	NSS_STATUS_SUCCESS,
	NSS_STATUS_NOTFOUND,
	NSS_STATUS_UNAVAIL,
	NSS_STATUS_TRYAGAIN,
	NSS_STATUS_RETURN
};
#endif /* _NSS_PGSQL_NETBSD_H */
