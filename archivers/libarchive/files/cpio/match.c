#include "cpio.h"

int
pathmatch(const char *p, const char *s)
{
	int r;
	int matched;
	const char *end;

	for (;;) {
		switch (*p) {
		case '[':
			++p;
			end = p;
			/* Leading ']' is non-special. */
			if (*end == ']')
				++end;
			while (*end != '\0' && *end != ']')
				++end;
			if (*end == '\0') { /* Unmatched '[' is plain char */
				if (*s != '[')
					return (0);
				++s;
				break;
			}
			matched = 0;
			while (!matched) {
				switch (*p) {
				case ']':
					if (p == end)
						return (0);
					else if (*s == ']') {
						p = end + 1;
						matched = 1;
						++s;
					} else
						++p;
					break;
				default:
					/* Trailing - is not special. */
					if (p[1] == '-' && p + 2 < end) {
						if (p[0] <= *s && *s <= p[2]) {
							p = end + 1;
							matched = 1;
							++s;
						} else
							p += 3;
					} else {
						if (*p == *s) {
							p = end + 1;
							matched = 1;
							++s;
						} else
							++p;
					}
				}
			}
			break;
		case '*':
			while (*p == '*')
				++p;
			if (*p == '\0')
				return (1);
			while (*s) {
				r = pathmatch(p, s);
				if (r)
					return (r);
				++s;
			}
			return (0);
			break;
		case '?':
			++p;
			++s;
			break;
		case '\0':
			return (*s == '\0');
			break;
		default:
			if (*p != *s)
				return (0);
			++p;
			++s;
			break;
		}
	}
}
