#ifndef LINPSK_PKGSRC_FIXES_H
#define LINPSK_PKGSRC_FIXES_H

#ifdef __NetBSD__
# include <sys/param.h>
#endif
#if !(defined(__NetBSD__) && __NetBSD_Version__ < 200000000)
# define HAVE_STRUCT_SCHED_PARAM
#endif

#if !(defined(__GNUC__) && (__GNUC__ < 3))
#  define HAVE_STD_VECTOR_AT
#endif

#ifdef __cplusplus
template <class T> typename T::reference at_replacement(T &c, const typename T::size_type &i) {
# ifdef HAVE_STD_VECTOR_AT
	return c.at(i);
# else
	return c[i];
# endif
}
#endif

#endif
