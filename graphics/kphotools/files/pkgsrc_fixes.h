#ifndef KPHOTOOLS_PKGSRC_FIXES_H
#define KPHOTOOLS_PKGSRC_FIXES_H

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
