package histogram

import (
	"fmt"
	"io"
	"sort"
)

type Histogram struct {
	histo map[string]int
}

func New() *Histogram {
	return &Histogram{make(map[string]int)}
}

func (h *Histogram) Add(s string, n int) {
	h.histo[s] += n
}

func (h *Histogram) PrintStats(caption string, out io.Writer, limit int) {
	entries := make([]entry, len(h.histo))

	i := 0
	for s, count := range h.histo {
		entries[i] = entry{s, count}
		i++
	}

	sort.Sort(byCountDesc(entries))

	for i, entry := range entries {
		fmt.Fprintf(out, "%s %6d %s\n", caption, entry.count, entry.s)
		if limit > 0 && i >= limit {
			break
		}
	}
}

type entry struct {
	s     string
	count int
}

type byCountDesc []entry

func (a byCountDesc) Len() int {
	return len(a)
}
func (a byCountDesc) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
func (a byCountDesc) Less(i, j int) bool {
	return a[j].count < a[i].count || (a[i].count == a[j].count && a[i].s < a[j].s)
}
